#!/bin/bash

array_size=500 # Number of elements in the array
print_all_outputs=0 # Flag to control whether to print all outputs or just the failed ones
num_failures=0 # Number of failed tests
operation_limit=5500 # Maximum number of operations allowed before a test is considered failed
ops=1000 # Nbr of tests to run
min_operations=9999999

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BOLD='\033[1m'
NC='\033[0m' # No Color

#Run ops nbr of tests
for (( i=1; i<=ops; i++ )); do
  # Generate a random array of integers between 1 and 10,000
  input_array=($(shuf -i 1-10000 -n $array_size | tr '\n' ' '))
  
  # Run the push_swap program with the input array, and count the number of operations
  num_operations=$(../push_swap "${input_array[@]}" | wc -l)
  
  # Print the number of operations if the print_all_outputs flag is set
  if [[ $print_all_outputs -eq 1 ]]; then
    echo -e "${BOLD}Test $i:${NC} ${input_array[@]} - $num_operations operations"
  fi
  
  # Increment the number of failed tests if the number of operations exceeds the limit
  if [[ $num_operations -gt $operation_limit ]]; then
    ((num_failures++))
    # Print the input array and the number of operations if the test failed and the print_all_outputs flag is not set
    if [[ $print_all_outputs -eq 0 ]]; then
      echo -e "${BOLD}Test $i:${NC} ${input_array[@]} - ${RED}${BOLD}$num_operations${NC} ${BOLD}operations${NC}" #> trace.txt
    fi
  fi
  # Update the maximum number of operations if this test exceeded the current maximum
  if [[ $num_operations -gt $max_operations ]]; then
    max_operations=$num_operations
  fi
  # Update the minimum number of operations if this test exceeded the current minimum
  if [[ $num_operations -lt $min_operations ]]; then
    min_operations=$num_operations
  fi
done

# Print the total number of failed tests and the maximum number of operations
echo -e "Number of failed tests: ${RED}$num_failures${NC}"
echo -e "Max number of operations: ${YELLOW}$max_operations${NC}"
echo -e "Min number of operations: ${GREEN}$min_operations${NC}"
