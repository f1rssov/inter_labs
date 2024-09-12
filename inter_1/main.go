package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strings"
	"log"
)

func main() {
	if(len(os.Args)!= 2){
		log.Fatalln("Enter name of one file")
	}
	// Открываем файл для чтения
	file, err := os.Open(os.Args[1])
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	// Стек для управления областями видимости переменных
	stack := []map[string]int{}

	// Регулярные выражения для разбора инструкций
	varSet := regexp.MustCompile(`(\w+)\s*=\s*(\d+)`)
	showVar := regexp.MustCompile(`ShowVar;`)
	oopen := regexp.MustCompile(`{`)
	cclose:= regexp.MustCompile(`}`)

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		line = strings.TrimSpace(line)

		// Обработка открытия блока
		if oopen.MatchString(line) {
			// Создаем новый уровень для переменных
			newScope := make(map[string]int)
			stack = append(stack, newScope)
			continue
		}

		// Обработка закрытия блока
		if cclose.MatchString(line) {
			if len(stack) > 1 {
				// Удаляем последний уровень и возвращаемся к предыдущему
				stack = stack[:len(stack)-1]
			}
			continue
		}

		// Обработка присвоения значения переменной
		if varSet.MatchString(line) {
			matches := varSet.FindStringSubmatch(line)
			varName := matches[1]
			varValue := matches[2]

			// Присваиваем значение переменной в текущем уровне стека
			currentScope := stack[len(stack)-1]
			value := 0
			fmt.Sscanf(varValue, "%d", &value)
			currentScope[varName] = value
			continue
		}

		// Обработка команды ShowVar
		if showVar.MatchString(line) {
			// Переменные видимые в текущем блоке
			fmt.Println("Variables:")
			currentScope := stack[len(stack)-1]
			for varName, varValue := range currentScope {
				fmt.Printf("%s = %d\n", varName, varValue)
			}
			continue
		}
	}

	// Проверяем наличие ошибок чтения
	if err := scanner.Err(); err != nil {
		fmt.Println("Error reading file:", err)
	}
}
