from openpyxl import Workbook

filename = "time_result"

write_wb = Workbook()

write_ws = write_wb.active
write_ws.append(['DIK', 'DIKPQ', 'DIKBQ', 'ASPQ', 'ASBQ', 'DIK', 'DIKPQ', 'DIKBQ', 'ASPQ', 'ASBQ'])
with open(filename + '.txt') as resultFile:
    lines = resultFile.readlines()
    resultDataList = {}
    resultRound = 0
    resultLength = 0
    resultTime = 0
    resultType = ''
    for line in lines:
        if line[:8] == "[Round: ":
            resultRound = int(line[8:-2])
            continue
        elif line[6:21] == '\'s SP length : ':
            resultType = line[0:5]
            resultType = resultType.strip()
            end = line.find('-')
            resultLength = int(line[21:end-1])
            start = line.find('Execution time is : ')
            start += len('Execution time is : ')
            resultTime = float(line[start:-1])
            resultDataList[resultType] = [resultLength, resultTime]
        elif line[0:1] == '\n':
            if len(resultDataList) == 0:
                continue
            allData = []
            for Type in resultDataList.keys():
                allData.append(resultDataList[Type][0])
            for Type in resultDataList.keys():
                allData.append(resultDataList[Type][1])
            write_ws.append(allData)
            resultDataList.clear()

write_wb.save(filename + '.xlsx')
