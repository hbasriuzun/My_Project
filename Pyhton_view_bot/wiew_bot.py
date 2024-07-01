import webbrowser,time
url = 'https://www.youtube.com/watch?v=1xbatv9QBas'

duration = int(input('Enter the duration: '))
views = int(input('Enter the number of views: '))

for i in range(views):
    webbrowser.open(url)
    time.sleep(duration)
    print(f'View {i+1} completed')





