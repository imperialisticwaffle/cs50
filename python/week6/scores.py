scores = [72, 73, 33]

print("Average: " + str(sum(scores) / len(scores)))
print(f"Average: {sum(scores) / len(scores)}")

new_scores = []

for i in range(3):
    scores.append(int(input("Input a score: ")))

average = sum(scores) / len(scores)
print("New average: " + str(average))