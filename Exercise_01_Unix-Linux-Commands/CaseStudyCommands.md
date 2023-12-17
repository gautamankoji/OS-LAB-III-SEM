# Case Study

## **Study of Unix/Linux general purpose utility command list: man, who, cat, cd, cp, ps, ls, mv, rm, mkdir, rmdir, echo, more, date, time, kill, history, chmod, chown, finger, pwd, cal, logout, shutdown.**

### (i) `man`

Short for "manual," `man` allows a user to format and display the user manual built into Linux distributions, which documents commands and other aspects of the system.

**Syntax:**

```bash
man [option(s)] keyword(s)
```

**Example:**

```bash
man ls
```

### (ii) `who`

Identifies the users currently logged in. The `who` command lets you display the users that are currently logged into your UNIX computer system.

**Syntax:**

```bash
who [OPTION]... [ FILE | ARG1 ARG2 ]
```

**Example:**

```bash
who am i
```

### (iii) `cat`

Concatenate or display files.

**Syntax:**

```bash
cat [-q] [-s] [-S] [-u] [-n[-b]] [-v [-t]] [- | File ... ]
```

**Exit Status:**

- `0`: All input files were output successfully.
- `>0`: An error occurred.

**Examples:**

1. Display a file at the workstation:

   ```bash
   cat notes
   ```

2. Concatenate several files:

   ```bash
   cat section1.1 section1.2 section1.3 >section1
   ```

3. Suppress error messages about files that do not exist:

   ```bash
   cat -q section2.1 section2.2 section2.3 >section2
   ```

4. Append one file to the end of another:

   ```bash
   cat section1.4 >>section1
   ```

   ...

### (iv) `cd`

The `cd` command, which stands for "change directory," changes the shell's current working directory.

**Syntax:**

```bash
cd directory
```

**Example:**

```bash
cd new
```

### (v) `cp`

Copy files and directories.

**Syntax:**

```bash
cp [option] source destination
```

**Example:**

```bash
cp file1 file2
```

### (vi) `ps`

Report a snapshot of the current processes.

**Syntax:**

```bash
ps [options]
```

### (vii) `ls`

List directory contents.

**Syntax:**

```bash
ls [option]
```

### (viii) `mv`

Move or rename files.

**Syntax:**

```bash
mv [option] source dest
```

**Example:**

```bash
mv file1 file2
```

### (ix) `rm`

Remove files or directories.

**Syntax:**

```bash
rm [option] filename
```

**Example:**

```bash
rm file1
```

### (x) `mkdir`

Make directories.

**Syntax:**

```bash
mkdir [option] directoryname
```

**Example:**

```bash
mkdir cse
cd cse
```

### (xi) `rmdir`

Remove empty directories.

**Syntax:**

```bash
rmdir [option] directoryname
```

**Example:**

```bash
rmdir cse
cd cse
```

...

Feel free to let me know if you want more information or if there's anything specific you'd like to add!
