clear all;
close all;
clc;

dt = 1/100;
t = [0:dt:10]';
x = sin(t);
data = [t,x];
sim('Test_Simin');