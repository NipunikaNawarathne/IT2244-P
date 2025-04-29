## 1. vi xyz.csv

**Opens the xyz.csv file in the vi text editor for viewing or editing.**

![1 vi](https://github.com/user-attachments/assets/b169fbdf-be32-4658-8e7d-aaff0be673c0)

## 2. wc -l xyz.csv

**Counts the number of lines in xyz.csv. (Here, it's 10)**

![2 word count](https://github.com/user-attachments/assets/a2d54ad3-2a27-496d-bf8e-5c5fa249a5e4)

## 3. cut -d',' -f 2 xyz.csv

**Extracts the 2nd column (ages) from the file using comma , as the delimiter.**

![3 select fields - cut](https://github.com/user-attachments/assets/33430c96-8b34-4b63-adbe-273d2cbfe3ad)

## 4. awk -F',' '{print $1}' xyz.csv

**Prints only the first field (names) from each line using comma , as the field separator.**

![4 select fields - awk](https://github.com/user-attachments/assets/1135c0b2-96aa-4747-87fc-a83a1ccada05)

## 5. cut -d',' -f 1,3 xyz.csv

**Extracts the 1st and 3rd columns (names and departments) from the file.**

![5 select fields - cut](https://github.com/user-attachments/assets/e16d3ff9-57c3-4b25-b6af-6e074f51490d)

## 6. head -3 xyz.csv

**Shows the first 3 lines of the file.**

![6 head](https://github.com/user-attachments/assets/adf5f79a-3a85-456a-8a6d-64ee82e9f0ac)

## 7. tail -5 xyz.csv

**Shows the last 5 lines of the file.**

![7 tail](https://github.com/user-attachments/assets/0a2eddcf-4a46-474f-8da0-2a21974e884a)

## 8. cut -d',' -f 2 xyz.csv > xyz1.csv

**Cuts the 2nd column (ages) and saves it into a new file xyz1.csv.**

## more xyz1.csv

**Displays the content of xyz1.csv one screen at a time (if long).**

![8 copy to xyz1](https://github.com/user-attachments/assets/28d08765-a462-48b6-91fa-691492ed0fed)

## 9. head -3 xyz.csv >> rows_xyz.csv

**Appends the first 3 lines of xyz.csv to the file rows_xyz.csv.**

## more rows_xyz.csv

**Displays the contents of rows_xyz.csv.**

![9 copy but not replace](https://github.com/user-attachments/assets/017509a9-449d-409b-9eea-7acdd9b2fe9e)



