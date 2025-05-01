def create_set():
    return []

def add_to_set(s, element):
    if element not in s:
        s.append(element)

def remove_from_set(s, element):
    if element in s:
        s.remove(element)

def set_contains(s, element):
    return element in s

def set_size(s):
    return len(s)

def set_iterator(s):
    return iter(s)

def set_intersection(set1, set2):
    return [elem for elem in set1 if elem in set2]

def set_union(set1, set2):
    return list(set(set1 + set2))

def set_difference(set1, set2):
    return [elem for elem in set1 if elem not in set2]

def is_subset(set1, set2):
    return all(elem in set2 for elem in set1)

def main():
    s1 = create_set()
    s2 = create_set()

    while True:
        print("\nMenu:")
        print("1. Add element to set 1")
        print("2. Add element to set 2")
        print("3. Remove element from set 1")
        print("4. Remove element from set 2")
        print("5. Check if an element is in set 1")
        print("6. Check if an element is in set 2")
        print("7. Intersection of sets")
        print("8. Union of sets")
        print("9. Difference of sets (Set 1 - Set 2)")
        print("10. Is Set 1 a subset of Set 2?")
        print("11. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            element = int(input("Enter element to add to set 1: "))
            add_to_set(s1, element)
            print("Element added to set 1.")

        elif choice == 2:
            element = int(input("Enter element to add to set 2: "))
            add_to_set(s2, element)
            print("Element added to set 2.")

        elif choice == 3:
            element = int(input("Enter element to remove from set 1: "))
            remove_from_set(s1, element)
            print("Element removed from set 1.")

        elif choice == 4:
            element = int(input("Enter element to remove from set 2: "))
            remove_from_set(s2, element)
            print("Element removed from set 2.")

        elif choice == 5:
            element = int(input("Enter element to check in set 1: "))
            print("Set 1 contains element:", set_contains(s1, element))

        elif choice == 6:
            element = int(input("Enter element to check in set 2: "))
            print("Set 2 contains element:", set_contains(s2, element))

        elif choice == 7:
            print("Intersection:", set_intersection(s1, s2))

        elif choice == 8:
            print("Union:", set_union(s1, s2))

        elif choice == 9:
            print("Difference (Set 1 - Set 2):", set_difference(s1, s2))

        elif choice == 10:
            print("Is Set 1 a subset of Set 2?", is_subset(s1, s2))

        elif choice == 11:
            print("Exiting...")
            break

        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()