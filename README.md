# Happy C
[happy C](https://github.com/HenryZhuHR/happyC) means code C happily.

# Struture
``` bash
.
├─app       # test file
├─bin       # binary output
├─conf
├─include   # head file
|   ├─LinkedList.hpp
|   └─...
├─src       # source file
└─tools # Download from release
    ├─cmake-3.20.1-windows-x86_64   # cmake
    └─mingw64                       # mingw 64
```

# mini Project



# Clang-Format
## Download
In [LLVM](https://llvm.org/builds/) official website, 
choose corresponding **Clang-Format** [Release](https://releases.llvm.org/) for your OS in **Other builds**. 

Then, you can download LLVM in this [page](https://releases.llvm.org/download.html) or in [Github Release](https://github.com/llvm/llvm-project.git)

when installing LLVM, select add LLVM to the system for **current/all user**.


## Usage
use `clang-format ` with parameter `-style` and `-i`
- `-style` LLVM、Google、Chromium、Mozilla、WebKit or file(.clang-format)
- `-i`
```
clang-format -style=LLVM -i test.c
```

or you can edit your custom format file [`.clang-format`](.clang-format), 
```
clang-format -i test.c
```

see [Clang documentation](https://clang.llvm.org/docs/ClangFormat.html) for more detail of using Clang-Format

# git
in file `.git/config`
```bash
[remote "origin"]
	url = https://github.com/<UserNAme>/<Repo>.git
	fetch = +refs/heads/*:refs/remotes/origin/*
```


# Code style guide
see [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)