# **Push_swap**
##### Grade **125/100**.
### **ABOUT**
This project involves sorting a stack A using a limited set of instruction and an auxiliary stack B in the least amount of movements possible. The bonus part involves the creation of a checker to verify that the set of movements produced by the `push_swap` program will result in a sorted stack.

### **Compilation/Execution**
To compile the program simple run `make`. This will create an executable called `push_back`. After this to launch the program run in your terminal the following command:

```sh
$ ./push_swap N1 N2 N3 N4 ...
```
Each argument corresponds to a number being inserted into the initial stack to be sorted. Any misconfiguration such as a non numerical, duplicate or int overflow should be handled as error and the program should display 'Error\n'.
The program will output the order of movements needed to perform in order to sort the stack.

To compile the `checker` for the bonus part run `make bonus`. After this simple redirect the output of the `push_swap` program into the `checker` and it will either output "Error\n", "OK\n" or "KO\n" depending on what the stack is sorted or not. Example:

```sh
$ ./push_swap N1 N2 N3 N4 ... | ./checker N1 N2 N3 N4 ...
```
