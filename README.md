# my_language

---

# Test with copy this file

```
./my_language ../test/test1.ma
./my_language ../test/test2.ma
./my_language ../test/game.ma
```

# Dependencies

---

```
sudo apt-get install libsdl2-dev
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
indent -linux main.c
indent -linux src/*.c
indent -linux src/*.h
```