import sys
import re

def parse_scores(file_path):
    scores = []
    with open(file_path, 'r') as file:
        for line in file:
            match = re.match(r'Score \d{4} = (\d+)', line)
            if match:
                scores.append(int(match.group(1)))
    return scores

def main():
    if len(sys.argv) != 3:
        print("Usage: python script.py file1.txt file2.txt")
        sys.exit(1)

    file1, file2 = sys.argv[1], sys.argv[2]

    # Parse the scores from the files
    scores1 = parse_scores(file1)
    scores2 = parse_scores(file2)

    # Compare the scores and output the result
    for index, (score1, score2) in enumerate(zip(scores1, scores2)):
        if score1 > score2:
            print(f"Index: {index}, {file1}: {score1}, {file2}: {score2}, diff : {score1 - score2}")

if __name__ == "__main__":
    main()
