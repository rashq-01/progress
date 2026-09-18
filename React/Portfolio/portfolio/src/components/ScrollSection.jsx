import { motion, useTransform, useMotionValue, animate } from "framer-motion";
import { useEffect, useRef } from "react";

// startP / endP = 0–1 scroll range where this section is active
export default function ScrollSection({ progress, startP, endP, children }) {
  // Section-local progress 0→1
  const local = Math.min(Math.max((progress - startP) / (endP - startP), 0), 1);
  const opacity = local < 0.1 ? local * 10 : local > 0.9 ? (1 - local) * 10 : 1;

  return (
    <motion.div
      className="fixed inset-0 z-10 flex flex-col justify-end pb-20 px-12 pointer-events-none"
      style={{ opacity }}
    >
      {children}
    </motion.div>
  );
}