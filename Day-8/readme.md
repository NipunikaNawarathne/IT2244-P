## 1. vi program1.csv

**Opens or creates the file program1.csv using the vi text editor for entering CSV data.**


![1 vi](https://github.com/user-attachments/assets/db8652ed-e505-4f01-9769-2cdfd60ffa16)

## 2. more program1.csv

**Displays the content of the file one screen at a time (handy for large files).**


![2 more](https://github.com/user-attachments/assets/72d70ec4-b593-472f-bb7e-4fc386c5b8b3)

## 3. grep 'Engineering' program1.csv

**Finds and shows only the lines containing "Engineering" in the file.**


![3 search](https://github.com/user-attachments/assets/6e25ce58-0464-4b09-94f6-df9720cf6449)

## 4. head -5 program1.csv

**Shows the first 5 lines of the file.**


![4 head](https://github.com/user-attachments/assets/ba59472c-c492-4137-97d3-68758ec2e871)

## 5. tail -4 program1.csv

**Shows the last 4 lines of the file.**


![5 tail](https://github.com/user-attachments/assets/2abdd3a9-5d1c-4ab3-bf3c-c54086a2b148)

## 6. wc -l program1.csv

**Counts the number of lines in the file (here: 11 lines).**


![6 word count](https://github.com/user-attachments/assets/3637c5c6-352c-4ca1-a565-2b5861b4011a)

## 7. awk -F, '{print NF; exit}' program1.csv

**Uses awk to:**

* Set the comma (,) as the field separator
* Print the number of fields (columns) in the first line (exit stops after the first line)


![7 Num of Fields](https://github.com/user-attachments/assets/36370111-e395-4ad3-a83d-c9c201a9976a)

## 8. awk -F, '{print $3}' program1.csv

**Prints the third column (Age) from each line.**


![8 print field](https://github.com/user-attachments/assets/3b363f2d-1ecc-4c0a-8bb7-7d8e88faf89b)

## 9. cut -d, -f 3 program1.csv

**Also prints the third field, using cut instead of awk.**


![9 print field using cut](https://github.com/user-attachments/assets/91319ee9-4871-47a2-8744-af88fd801c7f)

## 10. head -n8 program1.csv | tail -n1

**First takes the first 8 lines, then gets the last one of those (line 8 only).**


![10 get particular line](https://github.com/user-attachments/assets/fe6a990b-98e3-4d6f-8380-4b8656ea3b95)

## 11. awk -F, '{print $2,$3}' program1.csv >> xyzz.csv

**Appends the 2nd and 3rd columns (Name and Age) to a new file called xyzz.csv.**


![11 copy to xyzz](https://github.com/user-attachments/assets/8e54ed16-14ad-463b-a09a-ff03218c217e)

## 12. sort -t',' -k4,4nr program1.csv

**Sorts the file by the 4th column (Salary) in descending numeric order (nr = numeric reverse).**


![12 sort salary in reverse](https://github.com/user-attachments/assets/e2baccb6-f6f1-4e69-bedb-08aefcd1fffb)


## 13. sort -t',' -k4,4n program1.csv

**Sorts the file by Salary in ascending numeric order.**

![13 sort salary in reverse](https://github.com/user-attachments/assets/d3d1d5ec-b236-4a38-9357-8dc388b4822c)

## 14. sort -t',' -k5,5 program1.csv

**Sorts the file by Department (alphabetically).**


![14 sort by department in asc order](https://github.com/user-attachments/assets/e94f3d1e-c566-45ce-9e93-355d04446b80)

## 15. sort -t',' -k5,5 -k4,4nr program1.csv

**Sorts the file first by Department, and within each department, sorts by Salary in descending order.**


![15 sort by department then by salary](https://github.com/user-attachments/assets/6a426cf9-f22b-43d2-a9f2-30fe303f47ad)
