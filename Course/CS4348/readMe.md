# Starting the Project
1. Download and the extract the project files
2. Change the directory to extracted file by:
```bash
$ cd ./project2
```
3. To run the project type the command
```bash
$ make
```
4. If the Build is successful you will see the message:
```
$ Please run the Program by "./bin/project.out", and please do "make clean" before running again.
```
5. The Program requires the following required arguments:
    * Number of Machines in the network
    * Current Host ID
    * List of IP addresses
6. A sample run with 2 machines will be:
```bash
${dc31} ./bin/project.out 2 1 10.176.69.62 10.176.69.63
```
```bash
${dc32} ./bin/project.out 2 2 10.176.69.62 10.176.69.63
```