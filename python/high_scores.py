#High scores
#Demonstrate list methods

scores = []

choice = None

while choice != "0":
    
    print(
    """
    High Scores
    
    0 - Exit
    1 - Show Scores
    2 - Add a Score
    3 - Delete a Score
    4 - Sort Scores
    """    
    )
    
    choice = input("Choice: ")
    print()
    
    #Exit
    if choice == "0":
        print("Good Bye.")
        
    #List high score table
    elif choice == "1":
        print("HIgh Scores")
        for score in scores:
            print(score)
    
    #Add a score
    elif choice == "2":
        score = int(input("What score did you get?: "))
        scores.append(score)
        
    #Remove a score
    elif choice == "3":
        score = int(input("Remove which score?: "))
        if score in scores:
            socres.remove(score)
        else:
            print(score, "isn't in the high score list")
            
    #Sort scores
    elif choice == "4":
        scores.sort()
        scores.reverse()
        
    #Some unknown choice
    else:
        print("Sorry, but", choice, "isn't a valid choice.'")
        
input("\n\nPress the enter key to exit.")
