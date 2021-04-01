import matplotlib.pyplot as plt
from matplotlib.backends.qt_compat import QtGui
import numpy as np
import re
archivo=open("data.txt")
A=archivo.read().split("\n")
X=[]
Y=[]
Z=[]
for line in A:

    C=re.findall("[0-9]*",line)
    if len(C) > 1:
        X.append(int(C[0]))
        Y.append(int(C[2]))
        Z.append(int(C[4]))
colors = (0,0,0)
area = np.pi*3
plt.set_cmap("Greys")
plt.scatter(X, Y, s=area, c=Z, alpha=0.5)
plt.title("DLA")
plt.xlabel('x')
plt.ylabel('y')
plt.xlim([340, 650])
plt.ylim([250, 700])
plt.show()
plt.savefig("DLA.png")
