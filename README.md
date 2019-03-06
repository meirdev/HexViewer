## HexViewer

Small program for hex viewer.

`![](https://raw.githubusercontent.com/meirdev/HexViewer/master/Assets/Picture.png)`

### Benchmark

Random file:

`head -c 100MB < /dev/urandom > randomfile`

Result:

VS hexdump:

```
time ./HexViewer randomfile -t hexdump > hexviewer.txt

real    0m16.504s
user    0m14.203s
sys     0m1.984s

time hexdump -C randomfile > hexviewer.txt

real    0m43.754s
user    0m40.484s
sys     0m2.188s
```

VS hexyl:

```
time ./HexViewer randomfile -t hexyl > hexviewer.txt

real    0m39.504s
user    0m27.547s
sys     0m10.516s

time hexyl randomfile > hexviewer.txt

real    1m53.103s
user    0m35.297s
sys     1m15.109s
```