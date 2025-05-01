# Quadratic Probing
def insert(ht, n):
    key = int(input("Enter the key: "))
    loc = key % n
    
    if ht[loc] == -1: 
        ht[loc] = key
    else:
        step = 1
        cnt = 0
        loc1 = loc
        while ht[loc1] != -1:  
            cnt += 1
            loc1 = (loc + (step * step)) % n
            step += 1
            if loc1 == loc:
                print("Insertion fails!!!")
                break
        if ht[loc1] == -1:
            ht[loc1] = key
            print(f"Element {key} inserted at location {loc1}")

def display(ht):
    print("Hash table is as follows:")
    print(ht)

def searching(ht, n):
    ele = int(input("Enter the element to search: "))
    loc = ele % n
    step = 1
    loc1 = loc
    
    if ht[loc1] == ele:
        print(f"Element {ele} found at location {loc1}")
    else:
        while ht[loc1] != -1:
            if ht[loc1] == ele:
                print(f"Element {ele} found at location {loc1}")
                return
            loc1 = (loc + (step * step)) % n
            step += 1
            if loc1 == loc:  # If we looped back to the original location
                break
        print(f"Element {ele} not found.")

def main():
    n = int(input("Enter the hash table size: "))
    ht = [-1] * n  
    while True:
        print("Menu:")
        print("1. Insert")
        print("2. Display")
        print("3. Search")
        print("4. Exit")
        ch = int(input("Enter your choice: "))  
        if ch == 1:
            insert(ht, n)
        elif ch == 2:
            display(ht)
        elif ch == 3:
            searching(ht, n)
        elif ch == 4:
            break  # Exit the loop
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()