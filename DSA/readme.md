# Starting Scenarios
0. Change to the directory to the Project folder
```sh
> cd project
```
1. To run a scenario such as scenario_1, type
```sh
> bash scripts/scenario_1
```
2. This will automatically, compile the C++, clear the scenario_1 folder and make a new one. The topology file is also automatically created.

3. Kindly, wait for the nodes and controller to finish before running other scenarios. They will display a **done** message such as:
```sh
>
Node 0 Done
Node 1 Done
Node 2 Done
...
Controller Done
```
*Note: These messages may be out-of-order, I will try to learn more about linux kernal soon for scheduling.*  

4. All Scenarios are handled automatically such as giving correct arguments, killing Nodes (like Node 4 in Scenario 4) etc.