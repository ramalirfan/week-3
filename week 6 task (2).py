text=input("enter text")
letter=0
words=1
sentences=0
for char in text:
    if char.isalpha():
        letter+=1
    elif char == " ":
        words+=1
    elif char == ".":
        sentences+=1
L=(letter/words)*100
S=(sentences/words)*100
index=round(0.0588 * L - 0.296 *S - 15.8)
if index < 1:
    print("before grade: ")
elif index >= 16:
    print("grade 16+")
else:
    print(f"grade {index}")