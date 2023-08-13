import sys
from random import seed, randint
import random
import re


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


seed(int(cmdlinearg('seed', sys.argv[-1])))
maxN = int(cmdlinearg('maxN', 1000000))
aMaxDigits = int(cmdlinearg('AMaxDigits', 9))
last = int(cmdlinearg('last', 0))

N = int(cmdlinearg('N', random.randint(1, maxN)))

maxSingleDigit = int(cmdlinearg('maxDigit', 9))

currString = []

currNumberLen = 0

alfabet = "abcdefghijklmnopqrstuvwxyz"
characters = alfabet + alfabet.upper() + ".,;:?!"

while len(currString) < N:
    coinFlip = random.randint(0, 1)

    if coinFlip or currNumberLen == aMaxDigits:
        currString.append(characters[random.randint(0, len(characters)-1)])

        currNumberLen = 0
    else:
        currNumberLen += 1

        currString.append(str(random.randint(0, maxSingleDigit)))


currString = "".join(currString)

numbers = re.findall('\d+', currString)

if len(numbers) == 0:
    randIndex = random.randint(0, len(currString))

    currString = currString[:randIndex] + \
        str(random.randint(0, 9)) + currString[randIndex+1:]


numbers = re.findall('\d+', currString)

numbers = [*map(int, numbers)]

if last:
    lastNumber = str(numbers[-1])
    largestNumber = str(max(numbers))

    if lastNumber != largestNumber:
        allSegments = [[]]
        numberCurr = -1
        for a in currString:
            if a.isdigit():
                if numberCurr != 1:
                    allSegments[-1] = "".join(allSegments[-1])
                    allSegments.append([])
                    numberCurr = 1
                allSegments[-1].append(a)
            else:
                if numberCurr != 0:
                    allSegments[-1] = "".join(allSegments[-1])
                    allSegments.append([])
                    numberCurr = 0
                allSegments[-1].append(a)

        allSegments[-1] = "".join(allSegments[-1])

        for i in range(len(allSegments)):
            if allSegments[i] == str(largestNumber):
                for j in range(len(allSegments)-1, -1, -1):
                    if allSegments[j] == str(lastNumber):
                        allSegments[i], allSegments[j] = allSegments[j], allSegments[i]
                        break
                break

        currString = "".join(allSegments)


print(N)
print(currString)
