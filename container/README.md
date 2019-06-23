# Containerised LaTeX setup
Its docker container with [Texlive](http://www.tug.org/texlive/).

## Setup
- Make sure you have running docker setup
- Clone repository:
    ```bash
    git clone https://github.com/digitronik/LaTeX.git
    ```
- Create executable files:
    ```bash
    chmod +x LaTeX/container/*cont
    cp LaTeX/container/*cont /bin/.
    ```

**Note:** Above scripts are using [digitronik/latex](https://hub.docker.com/r/digitronik/latex) image which builds with current `Dockerfile`.
No need to build `Dockerfile` locally.



## Usages
- Run specific LaTeX command
    ```bash
    latexcont pdflatex foo.tex
    ```
- PDFLatex
    ```bash
    pdflatexcont foo.tex
    ```
- XELatex
    ```bash
    xelatexcont foo.tex
    ```

- Personally, I use [Kile](http://kile.sourceforge.net/) as my LaTeX IDE and integrate it easily 

    Settings > Configure kile > Build
    
    In PDFLaTeX > replace command `latex` with `pdflatexcont`
