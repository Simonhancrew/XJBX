# Latex论文撰写

首先安装textLive和vs code，在vscode中安装LaTex Workshop插件。之后就可以快乐的在vs code中做文章的排版了。另外也可以使用tex Studio

## tex概述

首先需要创建一个dir，创建一个新的目录来保存需要创建和保存的文件。然后在新的dir中创建出hello.tex的文件。需要注意的是，为了不给自己添麻烦，建议所有的路径和文件都必须是英文的。

```
\documentclass{article}
\usepackage{ctex}
\begin{document}
你好 hello \LaTeX{}
\end{document}
```

之后运行

```
xelatex hello.tex
```

你应该就可以看到hello.pdf的文件了。实际使用的时候一般都是选用相关的editor，没有再尝试使用命令行。

**tex的文件结构**

```
% 导言区（进行全局设置）
\documentclass{article} %book,report,letter

\title{My document}
\author{Han}
\date{\today}

\usepackage{ctex} % 导入的包，ctex是中文必须的

% 正文区
\begin{document} %document等
	\maketitle
	Hello
\end{document}
```

%开始的一行都是注释，注释不会参与编译。导言区的内容在文本区\maketitle会显现。正文区一个tex中只能有一个document环境。

然后双美元符是单行数学公式，$$xxxx$$会单独成行。

**中文的相关设置**

首先encoding必须是utf-8的，之后你要使用xelatex编译，最后要加入ctex的宏包。

```
% 导言区
\documentclass{article} %book,report,letter
\title{\heiti 文档}
\author{\kaishu Han}
\date{\today}
\usepackage{ctex} % 导入的包，ctex是中文必须的

% 正文区
\begin{document} %document等
	\maketitle
	hello
    let $f(x)$ be defined by the formula
    $$f(x) = 3x^2 + 1$$
你好啊
\end{document}
```





