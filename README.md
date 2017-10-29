# 21sh

## Description

The aim of this project is to recreate a shell with the following features:
- Pipes
- Redirections
- And and Or
- Builtins
- Line Editing

## Installation and Usage

1. Clone repository
2. Run next command in your terminal :

```
git clone https://github.com/jle-quel/21SH.git
cd 21sh
make && ./21sh
```
## Builtins Usage

```
Setenv: setenv [variable] [value]
Unsetenv: unsetenv [variables ...]
Echo: echo [arguments ...]
Exit: exit [argument]
Cd: cd [argument]
```

## Usage Example


```
/bin/ls | cat -e

cat << EOF >> foo ; cat foo | cat -e && echo $?

cd / && ls -l

ls 1>ok 2>err file1 file2 file2
```

## Author

Jefferson Le Quellec

