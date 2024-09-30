function a(a: int, b:int) -> None {
    print(f"{a} + {b} = {a + b}");
}

function b() -> List[int] {
    temp : List[int] = [];
    for (int i = 0 ; i < 10; i++) {
        temp.append(random(10));
    }
    return temp;
}

function main() {

    a();
    print(b);

}