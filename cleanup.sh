find . -path "./res" -prune -o \( -name "*.cpp" -o -type d \) | while read -r item; do
    if [ -d "$item" ]; then
        mkdir -p "res/$item"
    elif [ -f "$item" ] && [[ "$item" == *.cpp ]]; then
        cp --parents "$item" res
    fi
done