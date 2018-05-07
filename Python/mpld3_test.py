#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np
import mpld3

N = 20

fig, ax = plt.subplots()

x = np.random.rand(N)
y = np.random.rand(N)

ax.plot(x, y)
mpld3.save_html(fig,"figout.html")
mpld3.save_json(fig,"figout.json")

html = mpld3.fig_to_html(fig,"figout.json")
print html

#https://stackoverflow.com/questions/22981359/display-multiple-mpld3-exports-on-a-single-html-page
