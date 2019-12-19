if [ $# -lt 1 ]
then
    echo "$0 NewProject"
    exit 0
fi

mkdir -p $1
cd $1

cp ../_cpp_template/*  .
mv _cpp_template.cpp $1.cpp 
