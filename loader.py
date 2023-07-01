import requests
import subprocess
import os

def download_file(url, filename):
    response = requests.get(url)
    open(filename, 'wb').write(response.content)

def execute_file(filename):
    subprocess.call(['python', filename])

# example usage
url = 'http://example.com/file.py'  # URL to download the file
filename = 'downloaded_file.py'     # File name for the downloaded file

download_file(url, filename)
execute_file(filename)
