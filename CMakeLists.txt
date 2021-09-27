cmake_minimum_required(VERSION 3.20)
project(test_lang C)

set(CMAKE_C_STANDARD 99)

add_executable(Mod1Activity_1 "Module 1/Activity 1.c")
add_executable(Mod1Activity_2 "Module 1/Activity 2.c")
add_executable(Mod1Activity_3 "Module 1/Activity 3.c")
add_executable(Mod1Activity_4 "Module 1/Activity 4.c")

add_executable(Mod2Activity_1 "Module 2/Activity 1.c")
add_executable(Mod2Activity_2 "Module 2/Activity 2.c")
add_executable(Mod2Exercise_1 "Module 2/Exercise 1.c")

add_executable(Mod3Activity_1 "Module 3/Activity 1.c")
add_executable(Mod3Activity_2 "Module 3/Activity 2.c")
add_executable(Mod3Activity_3 "Module 3/Activity 3.c")

add_executable(MergingArrays "Practice Programs/Arrays/Merging Arrays.c")
add_executable(LoopsAndPointers "Practice Programs/Arrays/Loops and Pointers.c")
add_executable(TwoDimensionalArrays "Practice Programs/Arrays/Two-Dimensional Arrays.c")

add_executable(SingleLinkedList "Practice Programs/Linked List/Single Linked List.c")
add_executable(DoublyLinkedList "Practice Programs/Linked List/Doubly Linked List.c")

add_executable(StringManipulation "Practice Programs/Strings/String Manipulation.c")

add_executable(juju "Practice Programs/try/juju.c")