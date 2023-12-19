{ pkgs }: {
    deps = [
      pkgs.pandoc
      pkgs.glibcLocales
      pkgs.gitFull
      pkgs.cliquer
      pkgs.libev
      pkgs.gnuplot
      pkgs.ncurses.dev
      pkgs.gd
    ];
  env = {
    PYTHON_LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [
      pkgs.glibcLocales
      pkgs.gitFull
      pkgs.libev
    ];
  };
}