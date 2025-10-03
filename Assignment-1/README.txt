CPSC-2620 - Assignment 1
Name - Manpreet Singh
Date: October 03, 2024
Assignment: Turtle Graphics using CImg

About this Turtle project

This project is a  simple Turtle graphics program that draws lines on an  image using the CImg library. The Turtle can move around, turn, put its pen up or down, and draw on a shared canvas.

How I made the Turtle share the image

The Turtle class has a  special reference called std::reference_wrapper to hold the  image (CImg<unsigned char>)

This mean that many  Turtle object can use the same image without copying it

If one Turtle draw on the image  all other Turtles see the changes because they share the exact same image in memory

I use .get() when accessing the image inside the Turtle class because  reference_wrapper  is like a wrapper not the real image itself
 
Why I use std::reference_wrapper instead of a plain reference or pointer

A plain reference  (CImg<unsigned char>&) cannot be changed or copied easily that mean if you want to do something like  tbak = t it won’t work

std::reference_wrapper  lets me have a reference that can be copied and assigned  so the Turtle class works  well with copying and assignment

A pointer could work but reference_wrapper is simpler to use here because it acts like a reference but still support copying

Note: makefile will generate 3 different test 
 entering command ./test_* will generate 3 different images which shows the 3 diferent pattern made using turtle class




