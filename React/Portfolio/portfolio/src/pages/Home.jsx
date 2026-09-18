import { useScrollProgress } from "../hooks/useScrollProgress";
import ScrollCanvas from "../components/ScrollCanvas";
import ScrollSection from "../components/ScrollSection";

// Frame ranges per section
const SECTIONS = {
  intro:        { start: 0,   end: 0.2  },
  skills:       { start: 0.2, end: 0.4  },
  projects:     { start: 0.4, end: 0.6  },
  achievements: { start: 0.6, end: 0.8  },
  cta:          { start: 0.8, end: 1.0  },
};

export default function Home() {
  const progress = useScrollProgress();

  return (
    // Tall scroll container — 600vh gives smooth scroll room
    <div style={{ height: "600vh" }}>
      {/* Fixed visual layer */}
      <ScrollCanvas progress={progress} />

      {/* Dark gradient at bottom for text legibility */}
      <div className="fixed bottom-0 left-0 right-0 h-64 z-10 pointer-events-none"
           style={{ background: "linear-gradient(transparent, #050505cc)" }} />

      {/* SECTION 1 — INTRO */}
      <ScrollSection progress={progress} {...SECTIONS.intro}>
        <p className="text-white/50 text-sm tracking-widest uppercase mb-3">
          Welcome
        </p>
        <h1 className="text-white text-5xl font-light leading-tight mb-2">
          Hi, I'm Pritam Singh.
        </h1>
        <p className="text-white/60 text-xl font-light">
          Frontend Developer & Creative Engineer
        </p>
      </ScrollSection>

      {/* SECTION 2 — SKILLS */}
      <ScrollSection progress={progress} {...SECTIONS.skills}>
        <p className="text-white/90 text-3xl font-light leading-snug mb-3">
          I build modern, high-performance<br />web experiences.
        </p>
        <p className="text-white/40 text-base tracking-widest">
          React · Tailwind · Framer Motion · UI Engineering
        </p>
      </ScrollSection>

      {/* SECTION 3 — PROJECTS */}
      <ScrollSection progress={progress} {...SECTIONS.projects}>
        <p className="text-white/90 text-2xl font-light mb-2">
          Projects focused on performance,<br />design, and usability.
        </p>
        <p className="text-white/40 text-sm mb-8">
          Built with real-world production standards.
        </p>

        {/* 3 minimal project cards */}
        <div className="flex gap-4 pointer-events-auto">
          {[
            { title: "Project Alpha", tech: "React · Tailwind" },
            { title: "Project Beta",  tech: "Next.js · Framer" },
            { title: "Project Gamma", tech: "TypeScript · API" },
          ].map((p) => (
            <div key={p.title}
                 className="border border-white/10 px-5 py-4 rounded-sm
                            hover:border-white/30 transition-colors cursor-pointer">
              <p className="text-white/80 text-sm font-medium">{p.title}</p>
              <p className="text-white/30 text-xs mt-1">{p.tech}</p>
            </div>
          ))}
        </div>
      </ScrollSection>

      {/* SECTION 4 — ACHIEVEMENTS */}
      <ScrollSection progress={progress} {...SECTIONS.achievements}>
        <p className="text-white/90 text-3xl font-light mb-2">
          Consistent problem solver.
        </p>
        <p className="text-white/40 tracking-widest text-sm mb-6">
          DSA · Clean Architecture · Scalable UI
        </p>
        <div className="flex gap-8">
          <div>
            <p className="text-white text-2xl font-light">100+</p>
            <p className="text-white/30 text-xs mt-1">Problems Solved</p>
          </div>
          <div>
            <p className="text-white text-2xl font-light">5+</p>
            <p className="text-white/30 text-xs mt-1">Production Projects</p>
          </div>
        </div>
      </ScrollSection>

      {/* SECTION 5 — CTA */}
      <ScrollSection progress={progress} {...SECTIONS.cta}>
        <p className="text-white/90 text-3xl font-light mb-2">
          Let's build something impactful.
        </p>
        <p className="text-white/40 text-base mb-8">
          Available for frontend roles & freelance work.
        </p>
        <div className="flex gap-4 pointer-events-auto">
          <a href="/contact"
             className="px-6 py-3 bg-white text-black text-sm font-medium
                        hover:bg-white/90 transition-colors">
            Contact Me
          </a>
          <a href="/resume.pdf"
             className="px-6 py-3 border border-white/20 text-white/80 text-sm
                        hover:border-white/50 transition-colors">
            View Resume
          </a>
        </div>
      </ScrollSection>
    </div>
  );
}