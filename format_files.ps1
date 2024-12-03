# Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope CurrentUser

# Define the current directory as the root directory
$rootDir = Get-Location

# Recursively get all .c and .h files
$files = Get-ChildItem -Path $rootDir -Recurse -Include *.c, *.h

# Iterate over each file and run clang-format
foreach ($file in $files) {
    Write-Host "Formatting $($file.FullName)..."
    clang-format -style=file:.clang-format -i $file.FullName
    Write-Host "$($file.FullName) formatted."
}

Write-Host "Formatting completed."