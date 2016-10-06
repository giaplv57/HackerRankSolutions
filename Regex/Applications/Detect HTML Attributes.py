# Enter your code here. Read input from STDIN. Print output to STDOUT
# Bullshit and time-consuming challenge =,= Fuck this shit!
import re
import sys

lineNumber = raw_input();
allTag = {}

for i in range(int(lineNumber)):
    line = raw_input();
    for fullTagRaw in re.findall(r"(<(?:[a-z|0-9]*?) (?:.*?)[\"|'|/]>)|(<(?:[a-z|0-9]*?)>)", line):
        fullTag = fullTagRaw[0] if fullTagRaw[0] != "" else fullTagRaw[1]
        emptyTag = re.findall(r"^<([a-z|0-9]*?)>", fullTag)
        if emptyTag != []:
            allTag[emptyTag[0]] = set()
        else:
            tagName = re.findall(r"<(.*?) ", fullTag)[0]
            attributes = re.findall(r" (.*?)=[\"|'](?:.*?)[\"|']", fullTag)
            #print fullTag
            #print attributes
            allTag[tagName] = allTag[tagName]|set(attributes) if (tagName in allTag.keys()) else set(attributes)
            #print allTag[tagName]

sortedAllTag = sorted(allTag, key=lambda tag: tag[0])
for tagName in sortedAllTag:
    sys.stdout.write(tagName+":")
    attributes = sorted(allTag[tagName])
    for i in range (len(attributes)):
        sys.stdout.write(attributes[i])
        if i != len(attributes)-1: sys.stdout.write(",")
    print ''