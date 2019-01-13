echo "All the files in the present directory: "
ls

echo "A new directory has been created: "
mkdir new_dir
cd new_dir

i="y"

while [ $i = "y" ]
do

echo "1.List of files and directories"
echo "2.Create Directory"
echo "3.Create File"
echo "4.Rename file/directory"
echo "5.Delete file"
echo "6.Delete directory"
echo "7.Search a file"
echo "8.Check present directory"

echo "Enter your choice"
read ch
case $ch in

	1)ls;;
         		
    2)echo "Enter the new directory name : "
		read dname
		mkdir $dname

		echo "File and Directories in " $dname
		ls	;;
		
		
	3)echo "Enter the new file name with extension : "
		read fname
		gedit $fname

		echo "File and Directories in " $dname
		ls	;;
	

	4)echo "Enter the old file name to be renamed : "
		read old_fname
		echo "Enter the new file name to be renamed : "
		read new_fname
		mv $old_fname $new_fname

		echo "File and Directories in " $dname
		ls	;;
		
		
	5)echo "Enter the file name to be deleted : "
		read del_fname
		rm -f $del_fname
		echo "File and Directories in " $dname
		ls;;	
		

	6)echo "Enter the directory to be deleted : "
		read del_dir
		rm -rf $del_dir
		echo "File and Directories in " $dname
		ls	;;
		

	7)echo "Enter the file name to be searched : "
		read s_fname
		find . -name $s_fname;;
		

	8) pwd;;

	
		
    *)
         echo "Invalid choice";;
esac
echo "Do u want to continue ?"
read i
if [ $i != "y" ]
then
    exit
fi
done   
