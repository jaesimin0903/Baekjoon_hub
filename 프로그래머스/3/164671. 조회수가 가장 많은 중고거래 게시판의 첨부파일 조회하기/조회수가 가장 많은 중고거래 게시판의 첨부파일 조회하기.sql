-- 코드를 입력하세요
# SELECT CONCAT('/home/grep/src/',F.BOARD_ID,'/' ,F.FILE_ID, F.FILE_NAME , F.FILE_EXT)AS  FILE_PATH FROM USED_GOODS_FILE AS F
# JOIN (SELECT BOARD_ID, MAX(VIEWS) FROM USED_GOODS_BOARD LIMIT 1) AS B ON B.BOARD_ID = F.BOARD_ID
# ORDER BY F.FILE_ID DESC

SELECT CONCAT('/home/grep/src/',BOARD_ID,'/',FILE_ID,FILE_NAME,FILE_EXT) FILE_PATH
FROM USED_GOODS_FILE
WHERE BOARD_ID = (SELECT BOARD_ID FROM USED_GOODS_BOARD ORDER BY VIEWS DESC LIMIT 1)
ORDER BY FILE_ID DESC