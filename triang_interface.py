#!/usr/bin/env python2
import math
import random
import triang
import numpy as np
import matplotlib.pyplot as plt
import scipy.optimize as opt
import time

triang.cvar.delta=0.0725/2
triang.cvar.a=0.2
xin=np.array([np.pi*random.random(),np.pi*random.random(),np.pi*random.random()])
xbounds=np.array([[0.0,np.pi] for i in range(3)])

def V3(x):
    return triang.V3(x[0],x[1],x[2])

print(xin)
print(V3(xin))
xout=opt.basinhopping(V3,xin,niter=10000,minimizer_kwargs={'bounds':xbounds}).x
print(xout)
print(V3(xout))

my_dpi=80
plt.figure(figsize=(800/my_dpi,800/my_dpi),dpi=my_dpi) 
plt.axis('off')
fig=plt.gcf()
ax0=plt.subplot(111)
ax0.set_xlabel(r'$x$',fontsize=30)
ax0.set_ylabel(r'$y$',fontsize=30)

a=triang.cvar.a
d=triang.cvar.delta
k=triang.cvar.k

xt=np.array([0.0,a,a/2.0,0.0])
yt=np.array([0.0,0.0,math.sqrt(3.0)*a/2.0,0.0])

xdots=np.array([-d*math.cos(xout[0]),d*math.cos(xout[0]),None,a-d*math.cos(xout[1]),a+d*math.cos(xout[1]),None,a/2.0-d*math.cos(xout[2]),a/2.0+d*math.cos(xout[2])])
ydots=np.array([-d*math.sin(xout[0]),d*math.sin(xout[0]),None,-d*math.sin(xout[1]),d*math.sin(xout[1]),None,math.sqrt(3.0)*a/2.0-d*math.sin(xout[2]),math.sqrt(3.0)*a/2.0+d*math.sin(xout[2])])

na=np.newaxis
phi=np.linspace(0.0,2*np.pi,100)
x_line=xdots[np.where(ydots)][na,:]+k**-1*np.sin(phi[:,na])
y_line=ydots[np.where(ydots)][na,:]+k**-1*np.cos(phi[:,na])

ax0.plot(xt,yt,color='#000000',marker='x',markersize=25,linewidth=3,zorder=1)
ax0.plot(x_line,y_line,color='#080808',alpha=0.6,linestyle='--',linewidth=1,zorder=2)
ax0.plot(xdots,ydots,color='#0000FF',linewidth=5,zorder=3)
ax0.scatter(xdots,ydots,color='#00FF00',marker='o',s=300,zorder=4)

ax0.set_aspect('equal', 'datalim')

fig.tight_layout()
fig.savefig('triang'+time.strftime('-%Y-%j-%H-%M-%S')+'.pdf',dpi=my_dpi)

plt.close()
