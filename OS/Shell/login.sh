check_credentials() {
    local username=$1
    local password=$2

    local correct_username="test"
    local correct_password="test1234"

    if [[ "$username" == "$correct_username" && "$password" == "$correct_password" ]]; then
        echo "Login successful."
    else
        echo "Invalid username or password."
    fi
}

echo "Enter username: "
read username
echo "Enter password: "
read password

check_credentials "$username" "$password"
