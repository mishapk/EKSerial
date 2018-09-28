-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Сен 26 2018 г., 13:29
-- Версия сервера: 5.7.23
-- Версия PHP: 7.0.30-0+deb9u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `serials`
--
CREATE DATABASE IF NOT EXISTS `serials` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `serials`;

-- --------------------------------------------------------

--
-- Структура таблицы `chanels`
--

CREATE TABLE `chanels` (
  `ID` int(11) NOT NULL,
  `type_id` int(11) NOT NULL,
  `chanel_name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Структура таблицы `gauges`
--

CREATE TABLE `gauges` (
  `ID` int(11) NOT NULL,
  `type_id` int(11) NOT NULL COMMENT 'Тип прибора',
  `rel_date` date NOT NULL COMMENT 'Дата выпуска',
  `serial` varchar(12) NOT NULL COMMENT 'Серийный номер'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Структура таблицы `types`
--

CREATE TABLE `types` (
  `ID` int(11) NOT NULL,
  `name_gauge` varchar(40) NOT NULL COMMENT 'Имя устройства'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `chanels`
--
ALTER TABLE `chanels`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`,`type_id`),
  ADD KEY `ID_2` (`ID`,`type_id`),
  ADD KEY `type_id` (`type_id`);

--
-- Индексы таблицы `gauges`
--
ALTER TABLE `gauges`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`),
  ADD KEY `type_id` (`type_id`);

--
-- Индексы таблицы `types`
--
ALTER TABLE `types`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `chanels`
--
ALTER TABLE `chanels`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT для таблицы `gauges`
--
ALTER TABLE `gauges`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT для таблицы `types`
--
ALTER TABLE `types`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;
--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `chanels`
--
ALTER TABLE `chanels`
  ADD CONSTRAINT `chanels_ibfk_1` FOREIGN KEY (`type_id`) REFERENCES `types` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `gauges`
--
ALTER TABLE `gauges`
  ADD CONSTRAINT `gauges_ibfk_1` FOREIGN KEY (`type_id`) REFERENCES `types` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
