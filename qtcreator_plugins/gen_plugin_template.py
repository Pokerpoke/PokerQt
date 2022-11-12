#!/usr/bin/env python
# -*-coding:utf-8 -*-

import sys


def get_lower_case_name(text):
    lst = []
    for index, char in enumerate(text):
        if char.isupper() and index != 0:
            lst.append("_")
        lst.append(char)

    return "".join(lst).lower()


class_name = sys.argv[1]
widget_name = get_lower_case_name(class_name[1:])

print("--- generating ", class_name)

# .h
file_in = open("template/plugintemplate.tmh", "rt")
file_out = open("{}Plugin.h".format(class_name), "wt")

for line in file_in:
    cur_line = line
    cur_line = cur_line.replace("${CLASS_NAME}", class_name)
    cur_line = cur_line.replace("${WIDGET_NAME}", widget_name)
    file_out.write(cur_line)

file_in.close()
file_out.close()

# .h
file_in = open("template/plugintemplate.tmcc", "rt")
file_out = open("{}Plugin.cc".format(class_name), "wt")

for line in file_in:
    cur_line = line
    cur_line = cur_line.replace("${CLASS_NAME}", class_name)
    cur_line = cur_line.replace("${WIDGET_NAME}", widget_name)
    file_out.write(cur_line)

file_in.close()
file_out.close()

print("--- generated ", class_name)
