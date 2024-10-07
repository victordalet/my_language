# my_language

---

# Test with copy this file

```
print("Hello World!");
a = 31;
a = 42;
b = "salut";
print(f"Hello {a}!");
print(f"{b}");
c = [1,2,3]
print(f"{c}")
c.append(42)
print(f"{c}")
c.pop()
print(f"{c}")
c.append(7)
print(f"{c}")
d = 2
if (d <= 21): print("Test ok")
else: print("Test not ok")
if (d != 21): print("Test 2 ok")
else: print("Test 2 not ok")
if (d == 21): print("Test 3 not ok")
else: print("Test 3 ok")
if (d < 21): print("Test 4 ok")
print(f"{d}")
```

# Build

```
mkdir build-dir
cmake ..
make 
./my_language example.ma
```

# Indent

```
indent -linux src/*.c
```