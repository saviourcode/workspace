# Starting the Project
1. Download and the extract the project files
2. Change the directory to extracted file by:
```bash
$ cd ./project1
```
3. To run the project type the command
```bash
$ make
```
It will automatically build and compile the C Program and create the required directories "`./dir1`" and "`./dir2`".

4. If the Build is successful you will see the message:
```
$ Please run the Program by "./bin/project.out", and please do "make clean" before running again.
```
5. So, first check the contents of directory "`dir1`" and "`dir2`" by
```bash
$ ls ./dir1
$ ls ./dir2
```
6. You can even check the contents of the files by
```bash
$ cat ./dir1/file1
$ cat ./dir1/file2
$ cat ./dir2/file3
$ cat ./dir2/file4
```
7. After confirming everything above please run the project by
```bash
$ ./bin/project.out
```
8. Again repeat the steps 5 and 6, notice that both directories are now identical

> Note: If same file name is present in both the directories, we get into a conflict due to which this project does not touch such files and never overwrites them.