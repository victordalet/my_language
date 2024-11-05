d = 2
if (d <= 21): print("Test ok")
else: print("Test not ok")
if (d != 21): print("Test 2 OK")
else: print("Test 2 not ok")
if (d == 21): print("Test 3 not ok")
else: print("Test 3 ok")
if (d < 21): print("Test 4 ok")
#print(f"{d}")
system("touch test.txt")
while (d < 10): print(f"{d}"); d = d + 1