i="y"

while [ $i = "y" ]

do

  echo "PROGRAM MENU : "
  echo "1. Create a New Website Project. "
  echo "2. How Many Words are in the file. "
  echo "3. Get a resumen of the file. "

  echo "Enter Your Choice : "
  read ch

  case $ch in
    1)clear
      echo "1. Create a New Website Project. "
      echo ""
      echo "Enter Project Name :"
      read projectname

      mkdir  $projectname     #root folder
      echo "Root folder created..."

      cp index.html $projectname/index.html
      echo "File has been copied......"

      cd $projectname

      mkdir model
      mkdir controller
      mkdir views

      cd views

      mkdir css

      cd css

      cp ../../../main.css main.css

      cd ../

      mkdir js
      mkdir img
      echo "Project has been successfully created...." 
      ;;

    2)clear
      echo "2. How Many Words are in the file."
      echo ""
      read -p "Please insert the path of the file :" -i "$HOME/niru/" -e path
      echo ""
      echo ""
      echo -n "Enter name of the word :"
      read name
      echo "Total Number of $name"
      grep -ci $name $path $1
      echo ""
      echo "Display Match Lines and line number for $name : "
      grep -n $name $path $2
      ;;

    3)clear
      echo "Resumen of the file"
      echo ""
      echo ""
      read -p "Please insert the path of the file :" -i "$HOME/niru/" -e path
      echo ""
      echo "Number of lines in the file :"
      wc -l $path  $3
      echo ""
      echo "Number Of words in the file"
      wc -w $path $4
      echo ""
      echo "The length of longest line :"
      wc -L $path $5
      echo ""
      echo "Number of charecters in the file : "
      wc --char $path $6
      ;;

    *) default
       echo "OOOPs wrong choice."

  esac

echo "Do you want to continue(y/n) ?"
read i

if [ $i != "y" ]
then
   exit
fi
done    
