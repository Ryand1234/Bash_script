from urllib import request ,error
from urllib.request import Request,urlopen
import webbrowser
from subprocess import call
print("Paste the link of the video to play:")
url = input()
req = Request(url)
try:
	req1=urlopen(req)
except (error,e):
	if hasattr(e,'reason'):
		print ('We failed to reach a server.')
		print ('Reason: ', e.reason)
	elif hasattr(e,'code'):
		print ('The server couldn \t fulfill the request.')
		print ('Error code: ', e.code)
else:
	'webbrowser.open(url)'
	call(["bash ~/github/Bash_script/Project/youtube_downloader/download.sh " + url ],shell=True)
	
