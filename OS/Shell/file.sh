for file in a*; do
    if [ -f "$file" ]; then
        echo "Contents of $file:"
        cat "$file"
        echo
    fi
done
