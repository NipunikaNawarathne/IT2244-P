## 1. vi abc.tsv

**Opens the file abc.tsv in the vi text editor.**


![1 vi](https://github.com/user-attachments/assets/30e5fb1a-6d8c-4c18-a7b3-c6405937afc6)

## 2. ls

**Lists all files and directories in the current location.**


![2 ls](https://github.com/user-attachments/assets/215ca9c4-368a-4823-8f11-58bd7bf49151)

## 3. cut -d$'\t' -f 1 abc.tsv

**Cuts and shows only the 1st column from the file abc.tsv, using tab (\t) as the delimiter.**


![3 cut](https://github.com/user-attachments/assets/441f9fdd-7759-40e3-93a6-b8a32bfa5e47)

## 4. head -n 2 abc.tsv

**Shows the first 2 lines of the file.** 

![4 head](https://github.com/user-attachments/assets/a721abce-0263-4e0f-88df-a22fbcaf40d9)

## 5. tail -n 4 abc.tsv

**Shows the last 4 lines of the file.** 


![5 tail](https://github.com/user-attachments/assets/18c7ed2e-5d36-4264-971f-9a05a32123a3)


## 6. head abc.tsv

**Shows the first 10 lines of the file by default.**


![6 head all](https://github.com/user-attachments/assets/3aef0df1-1c7d-4823-b2e7-6d94097c9bb7)


## 7. Editing the file again with vi abc.tsv

**You opened abc.tsv again and added more lines manually using vi.**


![7 vi (re-add)](https://github.com/user-attachments/assets/8b914064-abc1-4cd5-a4f3-dfe78d6de489)


## 8. head -8 abc.tsv

**Shows the first 8 lines of the file.**


![8 head](https://github.com/user-attachments/assets/9798c1b1-91af-409f-a14d-e7e1f347a3e6)


## 9. tail -8 abc.tsv

**Shows the last 8 lines of the file.**


![9 tail](https://github.com/user-attachments/assets/894329dd-af50-4798-b46a-d0d07dfdd3df)


## 10. head -8 abc.tsv | tail -1

**First gets the first 8 lines, then shows the 8th line only.**


![10 get 8 row](https://github.com/user-attachments/assets/2780f26c-e11f-4b10-a59a-4198dae1aba7)


## 11. awk -F'\t' '{print NF; exit}' abc.tsv

**Uses awk to print the number of fields (columns) in the first line of the file using tab (\t) as the separator.**


![11 print num of fields](https://github.com/user-attachments/assets/3e302b4c-5dba-4c8f-8b10-9e9e7a97f995)


## 12. wc -l abc.tsv

**Counts the number of lines in the file.**


![12 Count tot lines](https://github.com/user-attachments/assets/9191f311-fc13-4d18-af60-9f2b37e31630)


## 13. head -n10 abc.tsv | grep 'bb'

**Searches for the string "bb" within the first 10 lines of the file.**


![13 search](https://github.com/user-attachments/assets/6966a253-4138-4246-89f2-65f809f3aab3)


