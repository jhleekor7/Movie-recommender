"""
2026-1 자료구조 과제 (OOP)

주제: 온라인 강의 플랫폼 (E-learning System)

구성:
- LectureADT (추상 클래스)
- Lecture (Base Class)
- VideoLecture / LiveLecture / QuizLecture (Sub Classes)

핵심 개념:
- Abstraction (추상화)
- Encapsulation (캡슐화)
- Inheritance (상속)
- Polymorphism (다형성)
"""

from abc import ABC, abstractmethod


# ---------------------------
# Step 1: ADT (추상 클래스)
# ---------------------------
class LectureADT(ABC):

    @property
    @abstractmethod
    def title(self):
        """강의 제목"""
        pass

    @property
    @abstractmethod
    def duration(self):
        """강의 길이"""
        pass

    @abstractmethod
    def play(self):
        """강의 재생"""
        pass

    @abstractmethod
    def stop(self):
        """강의 종료"""
        pass


# ---------------------------
# Step 2: Base Class
# ---------------------------
class Lecture(LectureADT):
    def __init__(self, title, duration):
        self._title = title          # 캡슐화
        self._duration = duration    # 캡슐화
        self._is_playing = False     # 상태 변수

    @property
    def title(self):
        return self._title

    @property
    def duration(self):
        return self._duration

    @property
    def is_playing(self):
        return self._is_playing

    def play(self):
        self._is_playing = True
        print(f"{self._title} 재생 시작")

    def stop(self):
        self._is_playing = False
        print(f"{self._title} 재생 종료")


# ---------------------------
# Step 3: Sub Classes (다형성)
# ---------------------------
class VideoLecture(Lecture):
    def play(self):
        self._is_playing = True
        print(f"{self.title} → 동영상 강의 재생 ▶️")


class LiveLecture(Lecture):
    def play(self):
        self._is_playing = True
        print(f"{self.title} → 실시간 강의 참여 🔴")


class QuizLecture(Lecture):
    def play(self):
        self._is_playing = True
        print(f"{self.title} → 퀴즈 풀이 시작 📝")


# ---------------------------
# Step 4: 실행 (테스트)
# ---------------------------
def main():
    lectures = [
        VideoLecture("파이썬 기초", 60),
        LiveLecture("자료구조 라이브", 90),
        QuizLecture("중간고사 대비 퀴즈", 30)
    ]

    for lec in lectures:
        print(f"[강의] {lec.title} | 길이: {lec.duration}분")
        lec.play()
        print(f"재생 상태: {lec.is_playing}")
        lec.stop()
        print("-" * 40)


if __name__ == "__main__":
    main()