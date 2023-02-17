-- 코드를 입력하세요
SELECT distinct(com.car_id)
from CAR_RENTAL_COMPANY_CAR com, CAR_RENTAL_COMPANY_RENTAL_HISTORY his
where com.car_id = his.car_id
and month(his.start_date) = '10'
and com.car_type = '세단'
order by com.car_id desc
;