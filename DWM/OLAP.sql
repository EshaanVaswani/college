SELECT * FROM public."SalesFact"
ORDER BY "SaleID" ASC 

SELECT s."Location", SUM(sa."Sales_Amount") AS total_sales
FROM public."SalesFact" AS sa
JOIN public."Store" AS s ON sa."StoreID" = s."StoreID"
JOIN public."Product" AS p ON sa."ProductID" = p."ProductID"
GROUP BY ROLLUP(s."Location");

SELECT p."ProductName", t."Month", SUM(sa."Sales_Amount") AS monthly_sales
FROM public."SalesFact" AS sa
JOIN public."Store" AS s ON sa."StoreID" = s."StoreID"
JOIN public."Time" AS t ON sa."TimeID" = t."TimeID"
JOIN public."Product" AS p ON sa."ProductID" = p."ProductID"
WHERE t."Year" = 2022
GROUP BY p."ProductName", t."Month";

SELECT sa.*, p."ProductName", s."Location"
FROM public."SalesFact" AS sa
JOIN public."Store" AS s ON sa."StoreID" = s."StoreID"
JOIN public."Product" AS p ON sa."ProductID" = p."ProductID"
WHERE s."Location" = 'Vashi';

SELECT sa.*, p."ProductName", s."Location"
FROM public."SalesFact" AS sa
JOIN public."Store" AS s ON sa."StoreID" = s."StoreID"
JOIN public."Time" AS t ON sa."TimeID" = t."TimeID"
JOIN public."Product" AS p ON sa."ProductID" = p."ProductID"
WHERE s."Location" IN ('Vashi', 'Bandra')
AND t."Year" IN (2022, 2023);

SELECT p."ProductName",
       SUM(CASE WHEN t."Month" = 1 THEN sa."Sales_Amount" ELSE 0 END) AS January,
       SUM(CASE WHEN t."Month" = 4 THEN sa."Sales_Amount" ELSE 0 END) AS April
FROM public."SalesFact" AS sa
JOIN public."Store" AS s ON sa."StoreID" = s."StoreID"
JOIN public."Time" AS t ON sa."TimeID" = t."TimeID"
JOIN public."Product" AS p ON sa."ProductID" = p."ProductID"
GROUP BY p."ProductName";


