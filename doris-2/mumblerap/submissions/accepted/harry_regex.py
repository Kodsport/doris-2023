#!/usr/bin/env python3
import re

input()

text = input()

#Använder regex för att hitta alla tal i inputen, och lägger det i en lista
numbers = re.findall(r'\d+', text)

#Gör om alla till integers
numbers = list(map(int,numbers))

print(max(numbers))
