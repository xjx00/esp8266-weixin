@echo off
git init
git config user.name "xjx00"
git config user.email "xjxyklwx@126.com"
git add .
git commit -m "Update"
git push --force --quiet "https://e70b4cd67dcc8bd57be55abbd32b8135a471854a@github.com/xjx00/esp8266-weixin.git" master:master