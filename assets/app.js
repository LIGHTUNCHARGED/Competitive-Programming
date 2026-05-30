(function () {
  const STORAGE_KEY = "cp-archive-theme";
  const root = document.documentElement;
  const savedTheme = localStorage.getItem(STORAGE_KEY);
  const preferredTheme = "light";

  root.dataset.theme = savedTheme || preferredTheme;

  window.CPArchive = {
    setTheme(theme) {
      root.dataset.theme = theme;
      localStorage.setItem(STORAGE_KEY, theme);
      document.querySelectorAll("[data-theme-label]").forEach((label) => {
        label.textContent = theme === "dark" ? "Dark mode" : "Light mode";
      });
    },
    toggleTheme() {
      this.setTheme(root.dataset.theme === "dark" ? "light" : "dark");
    },
    escapeHtml(value) {
      return String(value ?? "")
        .replaceAll("&", "&amp;")
        .replaceAll("<", "&lt;")
        .replaceAll(">", "&gt;")
        .replaceAll('"', "&quot;")
        .replaceAll("'", "&#039;");
    },
    formatProblemName(name) {
      return String(name ?? "").replaceAll("_", " ");
    },
    encodePath(path) {
      return String(path ?? "")
        .split("/")
        .map((part) => encodeURIComponent(part))
        .join("/");
    },
    ratingTheme(rating) {
      if (rating === "Unrated") return ["#64748b", "#334155", "Unrated"];
      const value = Number.parseInt(rating, 10);
      if (value < 1000) return ["#10b981", "#0891b2", "Newcomer"];
      if (value < 1200) return ["#06b6d4", "#2563eb", "Pupil"];
      if (value < 1400) return ["#3b82f6", "#7c3aed", "Specialist"];
      if (value < 1600) return ["#8b5cf6", "#c026d3", "Expert"];
      return ["#f43f5e", "#f97316", "Advanced"];
    },
    initThemeControls() {
      document.querySelectorAll("[data-theme-toggle]").forEach((button) => {
        button.addEventListener("click", () => this.toggleTheme());
      });
      this.setTheme(root.dataset.theme);
    }
  };

  document.addEventListener("DOMContentLoaded", () => window.CPArchive.initThemeControls());
})();
