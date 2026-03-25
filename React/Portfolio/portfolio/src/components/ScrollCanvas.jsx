import { useEffect, useRef } from "react";

const TOTAL_FRAMES = 176;

// Map scroll 0–1 to frame 1–176
function getFrameNumber(progress) {
  const frame = Math.round(progress * (TOTAL_FRAMES - 1)) + 1;
  return Math.min(Math.max(frame, 1), TOTAL_FRAMES);
}

// e.g. 1 → "ezgif-frame-001"
function padFrame(n) {
  return `ezgif-frame-${String(n).padStart(3, "0")}`;
}

export default function ScrollCanvas({ progress }) {
  const canvasRef = useRef(null);
  const imagesRef = useRef([]);
  const currentFrameRef = useRef(1);

  // Preload all frames on mount
  useEffect(() => {
    imagesRef.current = [];
    for (let i = 1; i <= TOTAL_FRAMES; i++) {
      const img = new Image();
      img.src = `/frames/${padFrame(i)}.jpg`; // adjust extension if .png
      imagesRef.current[i] = img;
    }
  }, []);

  // Draw frame on scroll
  useEffect(() => {
    const frameNum = getFrameNumber(progress);
    if (frameNum === currentFrameRef.current) return;
    currentFrameRef.current = frameNum;

    const canvas = canvasRef.current;
    const ctx = canvas?.getContext("2d");
    const img = imagesRef.current[frameNum];

    if (!ctx || !img) return;

    const draw = () => {
      canvas.width = canvas.offsetWidth;
      canvas.height = canvas.offsetHeight;

      // Cover fit — keeps subject centered
      const scale = Math.max(
        canvas.width / img.naturalWidth,
        canvas.height / img.naturalHeight
      );
      const x = (canvas.width - img.naturalWidth * scale) / 2;
      const y = (canvas.height - img.naturalHeight * scale) / 2;

      ctx.clearRect(0, 0, canvas.width, canvas.height);
      ctx.drawImage(img, x, y, img.naturalWidth * scale, img.naturalHeight * scale);
    };

    if (img.complete) draw();
    else img.onload = draw;
  }, [progress]);

  return (
    <canvas
      ref={canvasRef}
      className="fixed inset-0 w-full h-full z-0"
      style={{ background: "#050505" }}
    />
  );
}